//                                               -*- C++ -*-
/**
 *  @brief Pie class for piechart plots
 *
 *  Copyright 2005-2025 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <cstdlib>

#include "openturns/Pie.hxx"
#include "openturns/PersistentObjectFactory.hxx"
#include "openturns/ResourceMap.hxx"
#include "openturns/Log.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(Pie)

static const Factory<Pie> Factory_Pie;

/* Default constructor */
Pie::Pie()
  : DrawableImplementation()
  , radius_(1.0)
{
  // Force unused default color
  color_ = "blue";
  isColorExplicitlySet_ = true;
}

/* Default constructor */
Pie::Pie(const Point & data)
  : DrawableImplementation()
  , palette_(0)
  , radius_(1.0)
  , center_(2, 0.0)
  , labels_(0)
{
  // Force unused default color
  color_ = "blue";
  isColorExplicitlySet_ = true;
  // Check data validity
  setData(data);
  buildDefaultPalette();
  buildDefaultLabels();
}

/* Constructor with parameters */
Pie::Pie(const Point & data,
         const Description & labels)
  : DrawableImplementation()
  , palette_()
  , radius_(1)
  , center_(2, 0.0)
  , labels_(labels)
{
  // Force unused default color
  color_ = "blue";
  isColorExplicitlySet_ = true;
  // Check data validity
  setData(data);
  buildDefaultPalette();
}

/* Constructor with parameters */
Pie::Pie(const Point & data,
         const Description & labels,
         const Point & center,
         const Scalar & radius,
         const Description & palette)
  : DrawableImplementation()
  , palette_()
  , radius_(radius)
  , center_(center)
  , labels_(labels)
{
  // Force unused default color
  color_ = "blue";
  isColorExplicitlySet_ = true;
  if(!IsValidColorPalette(palette)) throw InvalidArgumentException(HERE) << "Given color palette = " << palette << " is incorrect";
  // Check data validity
  setData(data);
  palette_ = palette;
}

/* String converter */
String Pie::__repr__() const
{
  OSS oss;
  oss << "class=" << Pie::GetClassName()
      << " name=" << getName()
      << " labels=" << labels_
      << " radius=" << radius_
      << " center=" << center_
      << " color palette=" << palette_
      << " derived from " << DrawableImplementation::__repr__();
  return oss;
}

/* Accessor for center */
Point Pie::getCenter() const
{
  return center_;
}
void Pie::setCenter(const Point & center)
{
  center_ = center;
}

/* Accessor for radius */
Scalar Pie::getRadius() const
{
  return radius_;
}
void Pie::setRadius(const Scalar radius)
{
  radius_ = radius;
}

/* Accessor for labels */
Description Pie::getLabels() const
{
  return labels_;
}
void Pie::setLabels(const Description & labels)
{
  labels_ = labels;
}

/* Accessor for color palette */
Description Pie::getPalette() const
{
  return palette_;
}
void Pie::setPalette(const Description & palette)
{
  if(!IsValidColorPalette(palette)) throw InvalidArgumentException(HERE) << "Given color palette = " << palette << " is incorrect";
  palette_ = palette;
}

/* Accessor for boundingbox */
Interval Pie::getBoundingBox() const
{
  Point lowerBound(center_);
  lowerBound[0] -= (1.0 + ResourceMap::GetAsScalar("Pie-HorizontalMargin")) * radius_;
  lowerBound[1] -= (1.0 + ResourceMap::GetAsScalar("Pie-VerticalMargin")) * radius_;
  Point upperBound(center_);
  upperBound[0] += (1.0 + ResourceMap::GetAsScalar("Pie-HorizontalMargin")) * radius_;
  upperBound[1] += (1.0 + ResourceMap::GetAsScalar("Pie-VerticalMargin")) * radius_;
  return Interval(lowerBound, upperBound);
}

/* Clone method */
Pie * Pie::clone() const
{
  return new Pie(*this);
}

/* Check for color palette validity */
Bool Pie::IsValidColorPalette(const Description & palette)
{
  Bool IsValid = true;
  Description::const_iterator it;
  for(it = palette.begin(); it != palette.end(); ++it)
    IsValid &= IsValidColor(*it);
  return IsValid;
}

void Pie::checkData(const Point & data) const
{
  const UnsignedInteger size = data.getSize();
  // Check if there is any data to display
  if (!(size > 0))
  {
    throw InvalidArgumentException(HERE) << "No data to display";
  }

  // Then, check the positivity of the data
  Scalar xMax = 0.0;
  for (UnsignedInteger i = 0; i < size; ++i)
  {
    Scalar x = data[i];
    if (!(x >= 0.0))
    {
      throw InvalidArgumentException(HERE) << "Expected positive values, got " << x;
    }

    if (x > xMax) xMax = x;
  }

  // Check if there is at least one strictly positive data
  if (!(xMax > 0.0))
  {
    throw InvalidArgumentException(HERE) << "Expected at least one strictly positive data, but max=" << xMax;
  }
}

/* Build default palette
   Cycle through the hue wheel with 10 nuances and increasing darkness */
void Pie::buildDefaultPalette()
{
  palette_ = BuildDefaultPalette(data_.getSize());
}

/* Build default labels */
void Pie::buildDefaultLabels()
{
  const UnsignedInteger size = data_.getSize();
  labels_ = Description(size);
  Scalar sum = 0.0;
  for (UnsignedInteger i = 0; i < size; ++i) sum += data_(i, 0);
  for (UnsignedInteger i = 0; i < size; ++i) labels_[i] = String(OSS() << "L" << i << " " << 0.1 * round(1000.0 * data_(i, 0) / sum) << "%");
}

/* Method save() stores the object through the StorageManager */
void Pie::save(Advocate & adv) const
{
  DrawableImplementation::save(adv);
  adv.saveAttribute( "palette_", palette_ );
  adv.saveAttribute( "radius_", radius_ );
  adv.saveAttribute( "center_", center_ );
  adv.saveAttribute( "labels_", labels_ );
}

/* Method load() reloads the object from the StorageManager */
void Pie::load(Advocate & adv)
{
  DrawableImplementation::load(adv);
  adv.loadAttribute( "palette_", palette_ );
  adv.loadAttribute( "radius_", radius_ );
  adv.loadAttribute( "center_", center_ );
  adv.loadAttribute( "labels_", labels_ );
}

END_NAMESPACE_OPENTURNS
