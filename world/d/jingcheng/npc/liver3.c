//liver3.c
//by dwolf 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"���"NOR, ({ "xiu cai" }));
	set("shen_type", 1);

	set("str", 25);
	set("gender", "����");
	set("age", 16);
	set("long", "������Ȼ����ԣҲ������������Ŭ�����������ͳ������\n");
	set("combat_exp", 1000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
	   
        setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                YEL"�������Լ���֮�ϣ��������Լ���֮�ס�\n"NOR, 
		YEL"�ᵱ�������һ����ɽС��\n"NOR,
        }) );

	add_money("coin", 100);
}

