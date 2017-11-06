% Strong Types - Phantom Types
% Tobias Langner
% QtMeetup Ludwigsburg, 2017-06-22

----------------

## A standard problem
~~~{.cpp}
Date(int, int, int);
~~~

----------------

## it is

> - day, month, year (European)?
> - month, day, year (US)?
> - year, month, day (ISO)?

----------------

## the documentation says ...
~~~{.cpp}
//iso order
Date(int year, int month, int day);
~~~

----------------

~~~{.cpp}
Date d(1, 1, 1970); //1.1.1970
~~~

. . .

but that's easy to do wrong.

----------------

but the **main** difference between C and C++ is that we can define our own types. Shouldn't we do that?

----------------

## 1st try

~~~{.cpp}
using Year = int;
using Month = int;
using Day = int;

class Date {
public:
    //iso order
    Date(Year year, Month month, Day day);
};
~~~

. . .

... now we can't mix up the parameters anymore, right?

----------------

~~~{.cpp}
Date d(1, 1, 1970); //1.1.1970
~~~

. . .

... unfortunately this compiles. Using / typedef only create aliases, no real types.

----------------

## 2nd try

~~~{.cpp}
enum class UnitType { Year, Month, Day };

template<UnitType U> class Unit {
public:
	explicit Unit(int value) : value_(value) {}
	operator int() const { return value_; }
private:
	int value_;
};
...
~~~

. . .

U is called a "phantom type" because it does not appear in the body of the class

----------------

## 2nd try

~~~{.cpp}
using Year = Unit<UnitType::Year>;
using Month = Unit<UnitType::Month>;
using Day = Unit<UnitType::Day>;

class Date {
public:
	//iso order
	Date(Year year, Month month, Day day);
private:
	...
};
~~~

----------------

since we now have real types,

we can't mix them up anymore

~~~{.cpp}
//Date d(1, 1, 1970); - doesn't compile anymore
Date d(Year{ 1970 }, Month{ 1 }, Day{ 1 });
~~~

. . .

but the code looks ugly & heavy

----------------

## minor improvements

~~~{.cpp}
Year operator"" _y(unsigned long long v) { return Year(v); }
Month operator"" _m(unsigned long long v) { return Month(v); }
Day operator"" _d(unsigned long long v) { return Day(v); }
~~~

adding user defined literals

----------------

results in code that is easy to read

~~~{.cpp}
Date d(1970_y, 1_m, 1_d);
~~~

. . .

but still preserves the property of being hard to use wrongly

----------------

# Thank you

Any questions?

----------------

## Bonus: another use of phantom types

~~~{.cpp}
enum class Status { Verified, Unverified };

MyData<Unverified> ReadFromFile(...);
MyData<Verified> Verify(MyData<Unverified> data);
~~~

> - use the phantom type to indicate a status
> - for example that the data has been verified
> - just make sure that MyData<Verified> can't be created outside the verification function/method

----------------

# Thank you

More questions?