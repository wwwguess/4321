// sergeant.c

inherit NPC;

int chest_found = 0;

void create()
{
	set_name("���", ({ "sergeant" }) );
	set("long",
		"һλ��ò�������٣�����һ����վ�����﷢�����ƺ�����ʲô\n"
		"������������\n" );
	set("age", 29);
	set("combat_exp", 250000);
	set("env/wimpy", 10);
	set("str", 28);
	set("cor", 28);
	set("cps", 28);
	set("pursuer", 1);
	set("inquiry", ([
		"name" : "�����ճ£������棬�����ǣ�",
		"here" : "���ǲ��ɣ���Ҳ��������ģ�������ط�������Ϥ��",
		"rumors" : "����ʧ����һ����Ҫ���£���װ��һ����ľ�������֪����û�п�����",
		"����" : "�ԣ�����ľ���ɵ����ӡ�",
		"��ľ����" : "���������ˣ��鷳�ͻ����ң����¶������ر���",
		"������" : "���ң��������£���֪�����к�ָ�̣�"
	]) );
	set_skill("dodge", 70);
	set_skill("unarmed", 60);
	set_skill("parry", 70);
	set_skill("sword", 75);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 30);

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

int accept_object(object me, object ob)
{
	object book;

	if( !chest_found && ob->id("peach chest") ) {
		chest_found = 1;
		command("say ̫���ˣ�����������ӣ�");
		command("say ���³������⣬û��Я��̫������ ... ");
		command("say ������������Ļ����Ȿ�������Ц�ɡ�");
		book = new(__DIR__"obj/magic_book");
		book->move(this_object());
		command("give book to " + me->query("id"));
		delete("inquiry/rumors");
		delete("inquiry/����");
		delete("inquiry/��ľ����");
		return 1;
	}
	return 0;
}
