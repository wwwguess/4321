// Weapon: /d/new_taohua/obj/skysword.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "���콣" NOR, ({ "sword" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"����һ��������ˮ�ĳ���\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N�ӳ¾ɵĽ����аγ�һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

     init_sword(400);
        setup();

}
