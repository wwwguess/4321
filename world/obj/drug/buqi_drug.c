// snow-lotus-worm_grass.c ѩ����� made by datou 1998.3.16
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
    set_name(HIY "��֥" NOR, ({"ling zhi","ling","zhi"}));  
        if (clonep())
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("long", HIR "����һ�ż���������֥��������������Ĺ�Ч��\n" NOR);
                set("value", 50000);
        }
        setup();

}

int do_eat(string arg)
{
       object me=this_player();
       if (!id(arg))
              return notify_fail("��Ҫ��ʲô��\n");
       if ( ((int)me->query("eff_kee"))==((int)me->query("max_kee")) )
                      return notify_fail("��������������Ѿ�����Ҫ��������!\n",);
      else {
        if ( me->query("eff_kee") < me->query("max_kee") )
             me->set("eff_kee",((int)me->query("max_kee")));
    message_vision(HIY"$N�ó�һ����֥�������س�����ȥ!$N��ʱ��
���������������������۸��ˣ�\n"NOR, me);
           destruct(this_object());
            return 1;
         }
}                          
