// This file is part of OpenMVG, an Open Multiple View Geometry C++ library.

// Copyright (c) 2017 Romuald PERROT.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "RenderableObject.hh"

namespace openMVG_gui
{


/**
* @brief Ctr
* @param shader Shader to use for this object
* @param visible Indicate if object is visible
*/
RenderableObject::RenderableObject( std::shared_ptr<OpenGLContext> ctx ,
                                    std::shared_ptr<ShaderProgram> shader ,
                                    const bool visible )
  : m_context( ctx ) ,
    m_shader( shader ) ,
    m_is_visible( visible ) ,
    m_prepared( false )
{

}

RenderableObject::~RenderableObject( void )
{
  m_context->makeCurrent() ;
  destroyGLData() ;
  m_context->doneCurrent() ;
}


/**
* @brief Get model matrix
* @return current model matrix (in left hand system)
*/
openMVG::Mat4 RenderableObject::modelMat( void ) const
{
  return openMVG::Mat4::Identity() ;
}


/**
* @brief Get shader of the object
* @return current shader
*/
std::shared_ptr<ShaderProgram> RenderableObject::shader( void ) const
{
  return m_shader ;
}

/**
* @brief Set shader for this object
* @param shader New shader to assign to this object
*/
void RenderableObject::setShader( std::shared_ptr<ShaderProgram> shader )
{
  m_shader = shader ;
}

/**
* @brief Indicate if object should be rendered
* @retval true Object will be rendered
* @retval false Object won't be rendered
*/
bool RenderableObject::isVisible( void ) const
{
  return m_is_visible ;
}

/**
* @brief Set visibility of the object
* @param vis Visibility of the object
*/
void RenderableObject::setVisible( const bool vis )
{
  m_is_visible = vis ;
}

/**
* @brief Switch between visible/invisble state
*/
void RenderableObject::switchVisibility( void )
{
  m_is_visible = ! m_is_visible;
}

/**
* @brief destroy all openGL data (if any present)
*/
void RenderableObject::destroyGLData( void )
{
  m_shader = nullptr ;
}


} // namespace openMVG_gui
