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
		set("long", "����һ��ʮ�����Ĵ󻹵���\n");
		set("value", 100000);
	}
	setup();
}
void remove_effect(object me)
{
     me->delete_temp("dahuan");
     tell_object(me,HIY "�󻹵���Ч����ʼ��ʧ�ˡ�\n" NOR);
     destruct(this_object());
  }


int do_eat(string arg)
    {     object me,dh;   
          int num=0;
          me=this_player();
      if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
       num=me->query_temp("dahuan");
     if (num>1) { 
        tell_object(me,HIC "�󻹵���Ч����δ��ȫ�����������ٳ��ˡ�\n" NOR);
        return 1;
      }
        num++;
        me->set_temp("dahuan", num);
	me->add("kee",150);
	me->add("gin",150);
	me->add("sen",75);
        call_out("remove_effect",150,me);
	message_vision("$N����һ�Ŵ󻹵����ٲ�ȫ������ˬ !\n", this_player());
        dh=this_object();
        dh->move("/obj/sbaa/1"); 
	return 1;
}

