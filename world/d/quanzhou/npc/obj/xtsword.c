// Weapon: /d/new_taohua/obj/skysword.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
     set_name( HIG "������" NOR, ({ "sword" }) );
 set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"����һ��ɱ�����˵ı���\n"
);
   set("value", 10000);
                set("material", "steel");
                set("rigidity", 100000);
  set("wield_msg", "$N�ӳ¾ɵĽ����аγ�һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

 init_sword(400);
        setup();

}
