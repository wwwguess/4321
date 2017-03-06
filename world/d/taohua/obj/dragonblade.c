// Weapon: /d/new_taohua/obj/dragonblade.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name( HIR "������" NOR, ({ "blade" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "
    �������������ֳ��ۡ����첻����˭�����棡combine\n");
                set("material", "steel");
                set("wield_msg", "$Nһ���ֳ���һ��$n��\n");
                set("unwield_msg", "$N�����е�$n���뵶�ʡ�\n");
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
	message_vision("$N�����еĵ�����ն��������ϣ����е�����һ��ֽ��\n",me);
	commcase = new(__DIR__"ninebook2");
	commcase->move(me);
	dragonblade->move(environment(me));destruct(dragonblade);
}
else 
message_vision("$N�����е���������ϸ�о���һ����\n",this_player());

return 1;
}

