//NPC:/d/fgszhuang/npc/feihu.c
//by dwolf
//97.11.4 
         
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"ѩɽ�ɺ���"NOR, ({ "fei huli", "huli"}) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һͷ�ɰ��ķɺ��ꡣ����һ˫Բ������۾������㡣\n"
);
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);
        set("shen_type", -1);

        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                YEL"�ɺ��������������������㷢�������\n"NOR,
                RED"�ɺ���ͻȻ���˿�ȥ���㿪����Ĺ�����\n"NOR
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
        message_vision("$N��ҵؽ���һ�������ˣ�\n", this_object());
        ob = new(__DIR__"obj/hupi");
        ob->move(environment(this_object()));
        destruct(this_object());
}
