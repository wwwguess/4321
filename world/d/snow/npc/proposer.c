// proposer.c

inherit NPC;

string ask_for_employment();

void create()
{
	set_name("ý��", ({ "proposer" }) );
	set("gender", "Ů��" );
	set("long",
		"һ�����û�֦��չ�����긾�ˣ��������ļҹ�������˼����������\n"
		"����ȥ���ס�\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"employment" : (: ask_for_employment :),
		"����" : (: ask_for_employment :),
	]) );
	set("rank_info/respect", "����");
	set("age", 38);
	set("env/wimpy", 100);
	setup();
	carry_object(__DIR__"obj/color_cloth")->wear();
}

string ask_for_employment()
{
	object me;

	if( query_temp("proposing") ) return 0;

	me = this_player();
	if( !me->query("can_speak") )
		return "��Ӵ ... ����ҿ���Ц ... ȥ�Ҹ�ǣ���İɣ��ǺǺ� ...\n";
	if( (string)me->query("class")=="bonze" )
		return "������λ" + RANK_D->query_respect(me) + "�����Ȼ��װɣ��ǺǺ� ...\n";
	if( me->query("gender") != "����" )
		return "��λ" + RANK_D->query_respect(me) + "���ļ����е����������ȣ��ǺǺ� ...\n";
	command("giggle");
	if( me->query("spouce") ) 
		return "��λ" + RANK_D->query_respect(me) + "����θ�ڻ��治С�����ǺǺ� ...\n";
	if( query_temp("custom") )
		return me==query_temp("custom") ?
			  "�ǡ��ǡ� ���ǻ���ʲô������ȥ����λ����ɣ�\n"
			: "��һ���������˵����λ��ү�����£���һ�����ֵ��� ...\n";
	command("say �úúã��Ұ���ȥ˵(propose)׼�ɣ�������׼��һ������Ӵ ...");
	set_leader(me);
	command("say �����߰ɣ�");
	set_temp("custom", me);
}

int accept_order(object me, string verb)
{
	if( me==query_temp("custom") && verb=="propose" ) {
//		command("grin");
//		command("say �����ǹ��˶����£���� ... ��� ... ׼��������");
		return 1;
	}
	return 0;
}

int perform_propose(object ob)
{
	if( !ob || environment(ob)!=environment() ) {
		command("say �ף���λ�������أ�");
		set_leader(query_temp("custom"));
		delete_temp("proposing");
		return 0;
	}

	switch(query_temp("proposing")) {
		case 1:
			command("whisper " + ob->query("id") + query_temp("custom")->name()
				+ "��Ľ���Ѿ��ܾ��ˣ��ص�����������˵�� ...");
			add_temp("proposing", 1);
			return 1;
		case 2:
			command("whisper " + ob->query("id") + "�� ... ��������ǰ��һλ����Ʒ����ɣ�");
			add_temp("proposing", 1);
			return 1;
		case 3:
			command("nod " + query_temp("custom")->query("id") );
			command("whisper " + ob->query("id") + "��������⣬�͸��ҵ��ͷ(nod)�ɣ���Ȼҡҡͷ(shake)����ȥ��ɫ��Ķ��� ...");
			add_temp("proposing", 1);
			return 1;
		default:
			if( (int)query_temp("proposing") > 100 ) {
				command("sigh");
				command("say ������λ������������� ...");
				delete_temp("proposing");
				return 0;
			}
			switch(random(30)) {
				case 0:
					command("say " + query_temp("custom")->name()
					+ "��Ľ���Ѿ��ܾ��ˣ���֪���￼�ǵ�������");
					break;
				case 1:
					command("say " + query_temp("custom")->name()
					+ "��������Ʒ���ǲ����ˣ���������Ϊ�أ�");
					break;
				case 2:
					command("whisper " + ob->query("id") 
					+ "��������⣬�͵��ͷ(nod)�ɣ���Ȼҡҡͷ(shake)����ȥ��ɫ��Ķ��� ...");
					break;
				case 3:		command("smile"); break;
				case 4:		command("giggle"); break;
				case 5:		command("hmm"); break;
			}
			add_temp("proposing", 1);
			return 1;
	}
}

int force_me(string cmd)
{
	object me, ob;
	string target;

	if( sscanf(cmd, "propose %s", target) ) {
		me = this_player(1);
		ob = present(target, environment());
		if( !ob || !userp(ob) || !ob->query("can_speak")
		||	(string)ob->query("gender") != "Ů��") {
			command("?");
			command("say ˭��������Ĺ�������һλ��");
			return 0;
		}
		if( ob->query("spouce") ) {
			command("whisper " + me->query("id") + "�˼ҿ����з�֮��Ӵ�������ǿ��ǿ��ǰɣ�");
			return 0;
		}
		command("smile");
		command("whisper " + me->query("id") + " �����ģ����ҵģ�");
		command("smile " + ob->query("id"));
		set_temp("proposing", 1);
		set_leader(ob);
		start_busy( (: perform_propose, ob :) );
		return 1;
	}
	else return ::force_me(cmd);
}

int accept_object(object me, object obj)
{
}

void end_duty()
{
}
