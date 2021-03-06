// This file is part of openCaesar3.
//
// openCaesar3 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// openCaesar3 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with openCaesar3.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __OPENCAESAR3_EMPIRE_CITY_COMPUTER_H_INCLUDED__
#define __OPENCAESAR3_EMPIRE_CITY_COMPUTER_H_INCLUDED__

#include "oc3_empire_city.hpp"

class ComputerCity : public EmpireCity
{
public:
  static EmpireCityPtr create( EmpirePtr empire, const std::string& name );

  ~ComputerCity();

  std::string getName() const;
  Point getLocation() const;
  void setLocation( const Point& location );

  bool isDistantCity() const;

  void save( VariantMap& options ) const;
  void load( const VariantMap& options );

  const GoodStore& getSells() const;
  const GoodStore& getBuys() const;

  void resolveMerchantArrived( EmpireMerchantPtr );

protected:
  ComputerCity( EmpirePtr empire, const std::string& name );

private:
  class Impl;
  ScopedPtr< Impl > _d;

};

#endif //__OPENCAESAR3_EMPIRE_CITY_COMPUTER_H_INCLUDED__