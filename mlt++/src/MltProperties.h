/**
 * MltProperties.h - MLT Wrapper
 * Copyright (C) 2004-2005 Charles Yates
 * Author: Charles Yates <charles.yates@pandora.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _MLTPP_PROPERTIES_H_
#define _MLTPP_PROPERTIES_H_

#include <stdio.h>
#include <framework/mlt.h>

namespace Mlt 
{
	class Event;

	/** Abstract Properties class.
	 */

	class Properties 
	{
		private:
			mlt_properties instance;
		protected:
			virtual mlt_properties get_properties( );
		public:
			Properties( );
			Properties( bool dummy );
			Properties( Properties &properties );
			Properties( mlt_properties properties );
			Properties( const char *file );
			virtual ~Properties( );
			int inc_ref( );
			int dec_ref( );
			int ref_count( );
			void block( void *object = NULL );
			void unblock( void *object = NULL );
			void fire_event( const char *event );
			bool is_valid( );
			int count( );
			char *get( const char *name );
			int get_int( const char *name );
			double get_double( const char *name );
			void *get_data( const char *name, int &size );
			void *get_data( const char *name );
			int set( const char *name, const char *value );
			int set( const char *name, int value );
			int set( const char *name, double value );
			int set( const char *name, void *value, int size, mlt_destructor destroy = NULL, mlt_serialiser serial = NULL );
			int pass_values( Properties &that, const char *prefix );
			int parse( const char *namevalue );
			char *get_name( int index );
			char *get( int index );
			void *get_data( int index, int &size );
			void mirror( Properties &that );
			int inherit( Properties &that );
			int rename( const char *source, const char *dest );
			void dump( FILE *output = stderr );
			void debug( const char *title = "Object", FILE *output = stderr );
			void load( const char *file );
			int save( const char *file );
			Event *listen( char *id, void *object, mlt_listener listener );
			Event *setup_wait_for( char *id );
			void wait_for( Event *, bool destroy = true );
	};
}

#endif
