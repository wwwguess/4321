// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "master swordsman", "swordsman", "master" }) );
	set("nickname", "����˫��");
	set("gender", "����" );
	set("age", 44);
	set("str", 27);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force", 1200);
	set("force", 1200);

	set("long",
		"�������Ǹ��൱�ߴ�����������������Ǵ�����������ġ����ս�����\n"
		"��Ų²�����ǰ����������ŵ������˾��ǼҴ���ݵĹ�����\n");

	create_family("��ɽ����", 13, "������");

	set("combat_exp", 1000000);
	set("score", 200000);

	set_skill("unarmed", 40);
	set_skill("parry", 100);
	set_skill("dodge", 80);
	set_skill("sword", 100);
	set_skill("force", 40);
	set_skill("literate", 60);

	set_skill("fonxanforce", 60);
	set_skill("fonxansword", 100);
	set_skill("liuh-ken", 60);
	set_skill("chaos-steps", 100);
	set_skill("spider-array", 85);

	map_skill("unarmed", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");

	set("inquiry", ([
		"�������" : "����������ȸ�������������������������Ʒ�ɽ�Ż�����������������־��",
		"������־" : "�ȸ�����֮ʱ������ݽ����������У���úú��տ���",
		"����»" : "���ֵ��ں�������Ѿ������ˣ���ȥ֮�²������ᡣ"
	]) );

	setup();
	carry_object(__DIR__"blackthorn")->wield();
	carry_object(__DIR__"silk_cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if( ((int)ob->query("cor") < 20) 
	||	((int)ob->query("cps") < 20)) {
		command("say ѧ��֮�˱��뵨����ϸ�����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ˣ�");
		return;
	}
	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
