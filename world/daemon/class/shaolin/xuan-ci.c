// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;


void create()
{
	set_name("���ȴ�ʦ", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);


	set("nickname", CYN "������" NOR + RED "����" NOR);
        set("title", HIR "����" NOR + MAG "��ɮ" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("per", 25);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
	set("max_kee", 2500);
	set("max_gin", 1000);
	set("force", 3000);
	set("max_force", 3000);
	set("force_factor", 150);
	set("combat_exp", 4000000);
	set("score", 50000);

	set_skill("force", 180);
	set_skill("hunyuan-yiqi", 180);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 180);
	set_skill("finger", 110);
	set_skill("strike", 110);
	set_skill("sword", 180);
	set_skill("claw", 150);
	set_skill("parry", 180);
	set_skill("nianhua-zhi", 190);
	set_skill("damo-jian", 180);
	set_skill("fengyun-shou", 110);
	set_skill("longzhua-gong", 140);
	set_skill("buddhism", 180);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "damo-jian");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("sword", "damo-jian");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 36, "����");

	setup();
	carry_object("/d/shaolin/obj/damo-jian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
		this_player()->set("title",HIR "����" NOR + CYN "��Ħ��" NOR + RED "����" NOR);
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
		return;
	}

	return;
}

void init()
{
	::init();
        add_action("give_quest", "quest");
}


#include "/class/shaolin/xuan1.h"

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"��$N˫�ֺ�ʮ��˵���� ��������\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"��$N˫�ֺ�ʮ��˵���� �������գ���ú�ѧѧ������Ҫ����ɣ�\n" ,who);
    who->set("quest",0);
    return(0);
}

