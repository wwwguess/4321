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
    set_name(HIW "雪莲"NOR, ({"snow lotus","lotus"}));  
        if (clonep())
                set_default_object(__FILE__);
        else {
          set("unit", "朵");
          set("long", HIW "这是一朵天山上特产的雪莲，清香四溢！\n" NOR);

                set("value", 50000);
        }
        setup();

}

int do_eat(string arg)
{
       object me=this_player();
       if (!id(arg))
              return notify_fail("你要吃什么？\n");
       if ( ((int)me->query("eff_sen"))==((int)me->query("max_sen")) )
                return notify_fail("你的神气完足，已经不需要再疗养了!\n",);
      else {
        if ( me->query("eff_sen") < me->query("max_sen") )
             me->set("eff_sen",((int)me->query("max_sen")) );
    message_vision(HIY"$N拿出一朵雪莲，慢慢地吃了下去!$N顿时觉
得神清气爽，不再有劳累感了！\n"NOR, me);
           destruct(this_object());
            return 1;
         }
}                          
