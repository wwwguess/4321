//NPC:/d/suzhou/npc/xiaolu.c
//by dwolf
//97.11.4 
         
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"小鹿"NOR, ({ "xiao lu", "lu"}) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一头可爱的小鹿。正用一双圆溜溜的眼睛看着你。\n"
);
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000);
        set("shen_type", -1);

        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                YEL"小鹿轻轻地用头擦擦你，显得很可怜。\n"NOR,
                RED"小鹿突然跳了起来，仿佛受了惊吓。\n"NOR
        }) );

        set_temp("apply/attack", 10);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void die()
{
        object ob;
        message_vision("$N凄惨地叫了一声，死了！\n", this_object());
        ob = new(__DIR__"obj/lujiao");
        ob->move(environment(this_object()));
        destruct(this_object());
}
