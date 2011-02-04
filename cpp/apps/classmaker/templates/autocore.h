
#ifndef tu___H
#define tu___H

#include <qstring.h>
#include <qdatetime.h>
#include <qlist.h>
#include <qvariant.h>
#include <qimage.h>

#include "snl__.h"
#include "interval.h"
#include "bl__.h"

#define HEADER_FILES
<%BASEHEADER%>
#undef HEADER_FILES

class t__Schema;
class t__List;

typedef QList<QVariant> VarList;

/// @cond
<%CLASSDEFS%>
/// @endcond

<%CLASSDOCS%>
class snu___EXPORT t__ : public b__
{
public:
	/*
	 * Default constructor.  Creates a valid, uncommited t__ record.
	 */
	t__();

	/*
	 * Looks up the t__ record with primary key \param key
	 */
	t__( uint key );

	/*
	 * Constructs a shallow copy of \param other
	 */
	t__( const t__ & other ) : b__( other ) {}

	/*
	 * Constructs a shallow copy of \param r
	 * If r is not a derived from t__, then
	 * the record will be invalid.
	 */
	t__( const Record & r )
	: b__( r.mImp, false )
	{
		checkImpType();
	}

	t__( Stone::RecordImp * imp, bool checkType = true )
	: b__( imp, false )
	{
		if( checkType ) checkImpType();
	}
	
	/*
	 * Returns a copy of this record, with the primary key
	 * set to 0.
	 */
	t__ copy() const { return t__( Record::copy() ); }

	t__ & operator=( const t__ & other );

<%METHODDEFS%>

	static t__List select( const QString & where, const VarList & args );
	static t__List select( const QString & where = QString::null );
<%INDEXDEFS%>

<%ELEMENTHACKS%>

#define CLASS_FUNCTIONS
<%BASEHEADER%>
#undef CLASS_FUNCTIONS

	static Table * table();
	static t__Schema * schema();
private:
	void checkImpType();
};

#include "tl__list.h"
#include "tl__table.h"

#endif // tu___H

