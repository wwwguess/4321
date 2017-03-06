//NPC:/d/suzhou/npc/xiaolu.c
//by dwolf
//97.11.4 
         
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"С¹"NOR, ({ "xiao lu", "lu"}) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һͷ�ɰ���С¹������һ˫Բ������۾������㡣\n"
);
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000);
        set("shen_type", -1);

        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                YEL"С¹�������ͷ�����㣬�Եúܿ�����\n"NOR,
                RED"С¹ͻȻ�����������·����˾��š�\n"NOR
        }) );

        set_temp("apply/attack", 10);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void die()
{
        object ob;
        message_vision("$N��ҵؽ���һ�������ˣ�\n", this_object());
        ob = new(__DIR__"obj/lujiao");
        ob->move(environment(this_object()));
        destruct(this_object());
}
