// guiyuan.c �󻹵�sbaa 11.8
// solor 98.2.20
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("�󻹵�", ({"dahuan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY "����һ������ʥƷ���󻹵���\n" NOR);
		set("value", 200000);
	}
	setup();
}

int do_eat(string arg)
    {     object me,dh;   
          me=this_player();
      if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
	me->set("eff_kee",me->query("max_kee") );
	me->set("eff_gin",me->query("max_gin") );
	me->set("eff_sen",me->query("max_sen") );
	message_vision("$N����һ�Ŵ󻹵����ٲ�ȫ������ˬ !\n", this_player());
        dh=this_object();
	destruct(dh);
	return 1;
}

