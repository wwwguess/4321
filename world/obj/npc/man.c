inherit NPC;
inherit F_VENDOR;

void create()
{
	object ob;
	set_name("�ϰ�����", ({ "husband", "man" }) );
	set("gender", "����" );
	set("age", 42);
	set("combat_exp", 50000);
	set_skill("dodge",150);
	set_skill("throwing", 100);
	set("attitude", "friendly");
	setup();
	ob = carry_object("/d/hua/obj/dart");
	ob->set_amount(100);
	ob->wield();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob=this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	say("�ϰ�����˵������ɽ�����ϻ��������ˡ�Ӣ��Ҫ����Ϊ�����, \n���ǴӺ��������������, �Ǽ���СǮҲ������!\n");
}

int accept_object(object who, object ob)
{
	if (!ob->value()) {
		if (ob->name() == "����") {
			command("nod");
			message_vision("$N��Ϊ�����, ��Ӣ��Ҳ! \n", who);
			if (who->query("marks/���"))
				who->delete("marks/���");
			return 1;
		}
		if (ob->name() == "������") {
			command("nod");
			message_vision("$N�ܵ���ǧ�꺱���Ľ�����, ������Ե֮��! \n", who);
			if (who->query("marks/���"))
				who->delete("marks/���");
			return 1;
		}
		else {
			write("�ϰ�����ҡҡͷ˵���Ҷ���Щ������Ȥ��\n");
			return 0;
		}
	}
	else {
		tell_object(who, "���Ǯ������С�������ˡ�\n");
		return 0;
	}
}
