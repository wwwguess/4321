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
	set_name("����", ({"busen dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ʮ�����Ĳ��񵤡�\n");
		set("value", 5000);
	}
	setup();
}
void remove_effect(object me)
{
     me->delete_temp("busen");
     tell_object(me,HIY "���񵤵�Ч����ʼ��ʧ�ˡ�\n" NOR);
     destruct(this_object());
  }


int do_eat(string arg)
    {     object me,dh;   
          int num=0;
          me=this_player();
      if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
       num=me->query_temp("busen");
     if (num>1) { 
        tell_object(me,HIC "��Ĳ��񵤳Ե�̫���ˣ������ٳ��ˡ�\n" NOR);
        return 1;
      }
        num++;
        me->set_temp("busen", num);
	me->add("sen",50);
        call_out("remove_effect",150,me);
	message_vision("$N����һ�Ų��񵤣�ֻ������ɷ����ˬ !\n", this_player());
        dh=this_object();
        dh->move("/obj/sbaa/1"); 
	return 1;
}

