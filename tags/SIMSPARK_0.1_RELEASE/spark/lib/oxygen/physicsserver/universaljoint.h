/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-
   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2003 Koblenz University
   $Id$

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#ifndef OXYGEN_UNIVERSALJOINT_H
#define OXYGEN_UNIVERSALJOINT_H

#include "joint.h"

namespace oxygen
{
class Body;

class UniversalJoint : public Joint
{
public:
    UniversalJoint();
    virtual ~UniversalJoint();

    /** sets the joint anchor point. The joint will try to keep this
        point on each body together. The input is specified in local
        coordinates.
    */
    void SetAnchor(const salt::Vector3f& anchor);

    /** returns the joint anchor point in local coordinates on one of
        the two bodies. If the joint is perfectly satisfied, the joint
        anchor point will be the same for both bodies.
    */
    salt::Vector3f GetAnchor (EBodyIndex idx);

    /** This function sets up the first axis of the joint
        \param axis a vector describing the axis in relative coordinates
    */
    void SetAxis1(const salt::Vector3f & axis);

    /** This function sets up the second axis of the joint
        \param axis a vector describing the axis in local coordinates
    */
    void SetAxis2(const salt::Vector3f & axis);

    /** returns the vector describing one of the two axis
        (in local coordinates)
        \param idx index of the desired axis
    */
    salt::Vector3f GetAxis(EAxisIndex idx) const;

    /** returns one of the axis angles in degrees, measured between
        the two bodies, or between the body and the static
        environment.
    */
    float GetAngle(EAxisIndex idx) const;

    /** returns the time derivate of one of the hinge angles */
    float GetAngleRate(EAxisIndex idx) const;

    /** sets a joint parameter value */
    virtual void SetParameter(int parameter, float value);

    /** returns a joint parameter value */
    virtual float GetParameter(int parameter) const;

protected:
    /** creates a new universal joint */
    virtual void OnLink();
};

DECLARE_CLASS(UniversalJoint);

} // namespace oxygen

#endif // OXYGEN_UNIVERSALJOINT_H
