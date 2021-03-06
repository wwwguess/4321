//NPC:/d/fgszhuang/npc/feihu.c
//by dwolf
//97.11.4 
         
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"雪山飞狐狸"NOR, ({ "fei huli", "huli"}) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一头可爱的飞狐狸。正用一双圆溜溜的眼睛看着你。\n"
);
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);
        set("shen_type", -1);

        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                YEL"飞狐狸闪电般地跳起来，向你发起进攻。\n"NOR,
                RED"飞狐狸突然跳了开去，躲开了你的攻击。\n"NOR
        }) );               

	set("gin", 300);
	set("eff_jing", 300);
	set("kee", 500); 
	set("eff_qi", 500);
                            
	set_skill("dodge", 100);
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 20);

        setup();
}

void die()
{
        object ob;
        message_vision("$N凄惨地叫了一声，死了！\n", this_object());
        ob = new(__DIR__"obj/hupi");
        ob->move(environment(this_object()));
        destruct(this_object());
}
