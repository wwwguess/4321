// he.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(GRN"��֪��"NOR, ({ "he zizhang", "he" }));
	set("long", HIM"���˵�����ʫ�ˣ������˽�֪�������ھ��ǿ���һ����־���Ϊ��֪�ˡ�\n"NOR);
	set("gender", "����");
	set("per", 25);
	set("int", 30);
        set("age",57);
    set("vendor_goods",([
        "���ʫ��":__DIR__"obj/shi1",
        "�Ÿ�ʫ��":__DIR__"obj/shi2",
        "ׯ��":__DIR__"obj/tushu1",
        "����":__DIR__"obj/tushu2",
    ]));
	set_skill("literate", 300);
	set_skill("leadership", 200);

        set_skill("iron-cloth",50);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 100000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 8);
	set("chat_msg", ({
		YEL"��֪��������µ��룬��������������С����ϴ�أ�����δ����ë�ݡ�\n",
		YEL"��ͯ�������ʶ��Ц�ʿʹӺδ�����\n"NOR,
		MAG"���մ��׳�̾һ���������Ǿ��¾��ˣ��������� \n"NOR,
	        GRN"�þò�������ֵ��ˣ���֪���ǲ��ǻ�����ǰһ���þ�����\n"NOR,
	}) );
}
void init(){
    add_action("do_vendor_list","list");
}

int recognize_apprentice(object ob)
{
	if (ob->query("family/family_name")=="��͢")
		return 1;
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="literate")
	{
		if (me->query("family/family_name")=="��͢")
			return 1;
		if (!(int)me->query_temp("mark/��"))
			return 0; 
		me->add_temp("mark/��", -1);
		return 1;
	}

	return 0;
}
               

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	if (ob->query("money_id") && ob->value() >= 5000) {
		message_vision(HIM"��֪��ͬ��ָ��$NһЩ����д�ֵ����⡣\n"NOR, who);
		who->add_temp("mark/��", ob->value() / 50);
		return 1;
	}
	return 0;
}
