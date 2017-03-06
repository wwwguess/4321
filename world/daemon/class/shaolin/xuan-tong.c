// Npc: /kungfu/class/shaolin/xuan-tong.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("��ʹ��ʦ", ({
		"xuantong dashi",
		"xuantong",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ĸߴ�\n"
		"���ֹ�ϥ��˫Ŀ������գ�ȴ��ʱ���һ�ƾ��⡣\n"
	);


	set("nickname", CYN "����Ժ" NOR + RED "����" NOR);
        set("title", HIR "����" NOR + MAG "��ɮ" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
	set("max_kee", 1500);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("combat_exp", 2400000);
	set("score", 500000);

	set_skill("force", 140);
	set_skill("hunyuan-yiqi", 140);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 140);
	set_skill("parry", 140);
	set_skill("hand", 140);
	set_skill("claw", 140);
	set_skill("club", 140);
	set_skill("staff", 140);
	set_skill("zui-gun", 140);
	set_skill("pudu-zhang", 140);
	set_skill("qianye-shou", 140);
	set_skill("yingzhua-gong", 140);
	set_skill("buddhism", 140);
	set_skill("literate", 140);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "yingzhua-gong");
	map_skill("staff", "pudu-zhang");
	map_skill("club", "zui-gun");
	map_skill("parry", "yingzhua-gong");

	prepare_skill("finger", "nianhua-zhi");

	create_family("������", 36, "����");

	setup();

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

