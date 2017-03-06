// youngman.c

inherit NPC;

void create()
{
	set_name("����", ({ "youngman" }) );
	set("long", "һ����ò������������������ŵ�����������ľ��\n");
	set("age", 22);
	set("attitude", "peaceful");
	set("combat_exp", 2500);
	set("env/wimpy", 50);
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
	set("inquiry", ([
		"name": "�������Σ�����һ�����֣���֪������γƺ���",
		"here": "�����������سǣ�����������İɣ�",
		"trouble": ({
			(: command, "hmm" :),
			"ʵ��������������Ľǰ�������������Ĺ����Ѿ� ...",
			"����һֱ��֪��λ���﷼�� ...",
			"�� ..."
			}),
		"����" : "������λ��ȹ�����Ĺ��� ...",
	]) );
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	setup();
	carry_object(__DIR__"obj/hat")->wear();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

int accept_object(object me, object ob)
{
	if( !ob->id("###silk bag###") ) return 0;
	message("vision", name() + "һ��Ƴ���ɰ��ϵ�ԧ��ͼ��������һ�����˹�ȥ��\n"
		+ name() + "�漴�ӻ����ͳ�һ�����������澹Ҳ����һ����ͬ��ԧ��ͼ��\n", environment());
	command("say ԭ�������������ŵĻ��£���Ȼ�� ...");
	command("jump");
	delete("inquiry/trouble");
	return 1;	
}
