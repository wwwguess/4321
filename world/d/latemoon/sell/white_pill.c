#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
     set_name(HIW "�׷���" NOR ,({"white pill","pill" }));
	set("long",
   "����һ�Ŵ������������ӣ���������һ���ϵ�ҩ�ĵ�ζ����\n");
	set("unit", "��");
	set("base_unit", "��");
	set("base_weight", 200);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    if( !arg || arg != "pill")  return notify_fail("��Ҫ����ô��? \n");

	message_vision(
	   "$N�ó�һ�Ŵ����ӣ�һ�ڸ�������ȥ��\n"

	"ֻ��$Nȫ��ð��һ����̣������˿������ǳ��о���! \n",this_player());
    this_player()->receive_heal("gin", 100);
	this_player()->receive_heal("kee", 300);
	this_player()->receive_heal("sen",100);

	add_amount(-1);
	return 1;
}
