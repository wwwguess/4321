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
    set_name(HIY "虫草" NOR, ({"chong-grass","grass"}));  
        if (clonep())
                set_default_object(__FILE__);
        else {
          set("unit", "颗");
          set("long", "这是一颗极其珍贵的草药，具有滋阴壮阳，养精益肾
的妙用！\n");
                set("value", 50000);
        }
        setup();

}

int do_eat(string arg)
{
       object me=this_player();
      if (!id(arg))
        return notify_fail("你要吃什么？\n");     
       if ( ((int)me->query("eff_gin"))==((int)me->query("max_gin")) )
                      return notify_fail("你的精力已经不需要再疗养了!\n",);
      else {
        if ( me->query("eff_gin") < me->query("max_gin") )
             me->set("eff_gin",((int)me->query("max_gin")));
    message_vision(HIY"$N拿出一棵虫草，慢慢地吃了下去!$N顿时觉
得精力旺盛，不再有劳累感了！\n"NOR, me);
           destruct(this_object());
            return 1;
         }
}                          
