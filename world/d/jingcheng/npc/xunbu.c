// xunbu.c

#include <ansi.h>


inherit NPC;

void create()
{
        set_name("Ѳ��", ({ "xun bu", "xun", "bu" }));
        set("gender", "����");
        set("age", 35);
        set("long", "����һ�����ɵ�Ѳ����\n");

        set("combat_exp", 1000);
        set("shen_type", 1);
        set("pursuer", 2);
        set("max_force", 100);
        set("force", 100);
        set("force_factor", 5);

        set_skill("force", 20);
        set_skill("sword", 20);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/obj/weapon/changjian")->wield();
}



