// snow-lotus-worm_grass.c 雪莲虫草 made by datou 1998.3.16
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
    set_name(HIY "灵芝" NOR, ({"ling zhi","ling","zhi"}));  
        if (clonep())
                set_default_object(__FILE__);
        else {
          set("unit", "棵");
          set("long", HIR "这是一颗极其珍贵的灵芝，具有益气延年的功效。\n" NOR);
                set("value", 50000);
        }
        setup();

}

int do_eat(string arg)
{
       object me=this_player();
       if (!id(arg))
              return notify_fail("你要吃什么？\n");
       if ( ((int)me->query("eff_kee"))==((int)me->query("max_kee")) )
                      return notify_fail("你的神气饱满，已经不需要再疗养了!\n",);
      else {
        if ( me->query("eff_kee") < me->query("max_kee") )
             me->set("eff_kee",((int)me->query("max_kee")));
    message_vision(HIY"$N拿出一棵灵芝，慢慢地吃了下去!$N顿时觉
得神气饱满，不再有劳累感了！\n"NOR, me);
           destruct(this_object());
            return 1;
         }
}                          
