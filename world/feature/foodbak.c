// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	If( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !query("food_remaining") )
		return notify_fail( name() + "�Ѿ�ûʲ��óԵ��ˡ�\n");
	if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
	if( query("drink_func") )
		if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("�����̫���ˣ���Ҳ�Ų����κζ����ˡ�!\n");
	
	this_player()->add("food", query("food_supply"));
	if( query("drink_func") )
		this_player()->add("water", query("water_supply"));
	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	// This allows customization of drinking effect.
	//if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") ) {
		message_vision("$N��ʣ�µ�" + name() + "�Ե�ǬǬ������\n", this_player());
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
		message_vision("$N����" + name() + "ҧ�˼��ڡ�\n", this_player());

	return 1;
}

