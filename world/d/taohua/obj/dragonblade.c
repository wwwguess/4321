// Weapon: /d/new_taohua/obj/dragonblade.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name( HIR "屠龙刀" NOR, ({ "blade" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
    宝刀屠龙，武林称雄。倚天不出，谁与争锋！combine\n");
                set("material", "steel");
                set("wield_msg", "$N一伸手抄起一把$n。\n");
                set("unwield_msg", "$N将手中的$n插入刀鞘。\n");
        }
     init_blade(500);
        setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_combine","combine");
}

int do_combine()
{
int i,ss=0,db=0;
object commcase,me, *inv;
object skysword,dragonblade;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == __DIR__"skysword") {ss = 1; skysword = inv[i];}
                        if(base_name(inv[i]) == __DIR__"dragonblade") {db = 1; dragonblade = inv[i];}
                        i++;
		}

if( ss )
{
        skysword->move(environment(me));destruct(skysword);
	message_vision("$N把手中的刀剑互斩，刀剑齐断，从中掉出了一个纸卷。\n",me);
	commcase = new(__DIR__"ninebook2");
	commcase->move(me);
	dragonblade->move(environment(me));destruct(dragonblade);
}
else 
message_vision("$N把手中的屠龙刀仔细研究了一番．\n",this_player());

return 1;
}

