// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�سǹٱ�", ({ "town guard", "guard" }) );
	set("long",
		"���Ǹ���������վ�ڵ��سǹٱ�����Ȼ����\������������������ٱ�\n"
		"�ǵ��书\ʵ��ϡ��ƽ������������������֯���м��ɵ�սʿ��˭Ҳ��\n"
		"���׵��������ǡ�\n");

	set("attitude", "peaceful");
	set("vendetta_mark", "authority");

	set("str", 27);
	set("cor", 26);
	set("cps", 25);

	set("combat_exp", 100000);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"�سǹٱ��ȵ�������������������־͸���\n",
		"�سǹٱ��ȵ����󵨵��񣡾���ɱ���췴��\n"
	}) );

	set_skill("unarmed", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("move", 100);

	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 70);
	set_temp("apply/move", 100);

	setup();

	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

