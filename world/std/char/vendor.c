// vendor.c

#include <dbase.h>
#include "/std/char/dealer.c" 
void reset()
{
	reload_object(this_object());
}

string accept_buy(object me, string what)
{
	mapping list;
	string *item;
	int i, index;
	string what_name;

	if( sscanf(what, "%s %d", what_name, index) != 2 ) {
		index = 1;
//	here if what == " a b" then what_name="a" now
//	so reset what_name , by cmy 971204
		what_name = what;
	}
	if( mapp(list = query("vendor_goods")) ) {
		item = keys(list);
		for(i=0; i<sizeof(item); i++) {
			if( item[i]->id(what_name) ) {
				--index;
				if( !index ) return item[i];
			}
		}
	}
	return 0;
}

int query_trading_price(string handle)
{
	mapping list;

	if( !mapp(list = query("vendor_goods")) )
		return 0;
	if( undefinedp(list[handle]) ) return 0;

	return handle->query("value");
}

void compelete_trade(object me, string what)
{
	mapping list;
	string ob_file;
	object ob;

	list = query("vendor_goods");
	if( !undefinedp(list[what]) ) {
		ob = new(what);
		ob->move(me);
		message_vision("$N��$n����һ" + ob->query("unit") + ob->query("name") + "��\n",
			me, this_object() );
	}
}

string price_string(int v)
{
	if( v%10000 == 0 )
		return chinese_number(v/10000) + "���ƽ�";
	if( v%100 == 0 )
		return chinese_number(v/100) + "������";
	return chinese_number(v) + "��Ǯ";
}

int do_vendor_list(string arg)
{
	mapping goods;
	string list, *name;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	if( arg && !this_object()->id(arg) ) return 0;
	name = keys(goods);
	list = "����Թ���������Щ������\n\n";
	for(i=0; i<sizeof(name); i++)
		list += sprintf("  %-30s��%s\n",
			name[i]->short(),
			price_string(name[i]->query("value")) );
	write(list);
	return 1;	
}
