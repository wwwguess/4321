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
    set_name(HIW "ѩ��"NOR, ({"snow lotus","lotus"}));  
        if (clonep())
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("long", HIW "����һ����ɽ���ز���ѩ�����������磡\n" NOR);

                set("value", 50000);
        }
        setup();

}

int do_eat(string arg)
{
       object me=this_player();
       if (!id(arg))
              return notify_fail("��Ҫ��ʲô��\n");
       if ( ((int)me->query("eff_sen"))==((int)me->query("max_sen")) )
                return notify_fail("����������㣬�Ѿ�����Ҫ��������!\n",);
      else {
        if ( me->query("eff_sen") < me->query("max_sen") )
             me->set("eff_sen",((int)me->query("max_sen")) );
    message_vision(HIY"$N�ó�һ��ѩ���������س�����ȥ!$N��ʱ��
��������ˬ�����������۸��ˣ�\n"NOR, me);
           destruct(this_object());
            return 1;
         }
}                          
