inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "���㻨" NOR, ({"hua", "baixiang"}));
        set("unit", "��");
	set("long", "����һ�����޵Ļ�������Ũ���쳣��\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if(arg=="hua") 
{
this_player()->add("max_force",5);
 this_player()->unconcious();
destruct(this_object());
}
return 1;
}
