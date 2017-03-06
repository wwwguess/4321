// mercenary.c

inherit NPC;
inherit F_MERCENARY;

void create()
{
	set_name("����", ({ "pangyi" }) );
	set("age", 33);
	set("race", "����");
	set("long",
		"�����Ƿ�ɽ���к�������ͬ���ĵ��ӣ��������Ժöĵ���������ʦ��\n"
		"��ͬ��ʦ�ֵܵ�ϲ������˱�����ߣ�ȴδ�����������κ���Ҫְ��\n"
		"�����徭�������������Ի�����У�ʵ���ծ�������Ź��ֲ�������\n"
		"��ҽ���Ĺ�������˾����Ĵ�Ѱ��׬Ǯ���ƵĻ��ᡣ\n");
	set("max_force", 600);
	set("force", 1000);

	set("inquiry", ([
		"׬Ǯ": "��ģ�������Ǯ׬��",
		"����": "�����ҵ������룬ֻҪ���˿Ϲ���(employment)�ң��ֱ��м��������Ӿͺ��ˡ�",
		"employment": "�ǵģ�һ��һ�������ӣ�ֻҪ��Υ����������ҿ������κ��¡�",
		"������": "������������ͬ��ʦ�֡�",
		"��": ({ (: command, "hmm" :),
				 (: command, "grin" :),
				 "�������Ҳ���ô˵�����������ֵ�������漸�֣�" }),
	]) );
	create_family("��ɽ����", 13, "����");
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 80);
	set_skill("move", 80);
	set_skill("force", 65);
	set_skill("fonxanforce", 80);
	set_skill("fonxansword", 80);
	set_skill("chaos-steps", 70);
	set_skill("liuh-ken", 80);
	set_skill("literate", 60);
	map_skill("sword", "fonxansword");
	map_skill("unarmed", "liuh-ken");
	map_skill("dodge", "chaos-steos");
	map_skill("force", "fonxanforce");
	
	setup();

	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();
}

int accept_object(object me, object ob)
{
	if( query("on_duty") ) {
		command("say �Բ�������Ŀǰ���������ͣ��������������");
		return 0;
	}
	if( (int)ob->value() < 10000 ) {
		command("say �� ... ���º�������������ǣ���ذɡ�");
		return 0;
	}
	command("smile");
	command("say ̫���ˣ����µ��зԸ�����ĳ���������Ը���");
	command("follow " + me->query("id"));
	set("boss_id", me->query("id"));
	set("on_duty", 1);
	call_out("duty_end", ((int)ob->value() / 10000) * 1440 );
	return 1;
}

void duty_end()
{
	object home;

	delete("on_duty");
	command("tell " + query("boss_id") + " ����͵���Ϊֹ�����ɸ����չˣ�������ڡ�");
	command("say ��ĳ��ǡ�");
	home = find_object(query("startroom"));
	if( home ) return_home(home);
	else destruct(this_object());
}

