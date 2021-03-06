// guard.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("门卫",({"hhu-guard","guard"}));
        set("long",@LONG
这个门卫看上去很面善
LONG
);

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000);

        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("move", 100);

        set_temp("apply/attack", 90);
        set_temp("apply/defense", 90);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 90);
        set_temp("apply/move", 100);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}
