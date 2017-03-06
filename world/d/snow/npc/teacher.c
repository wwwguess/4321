// teacher.c

inherit NPC;

void follow_player();

void create()
{
	set_name("κ�޼�", ({ "teacher", "wey" }) );
	set("title", "��������");
	set("gender", "����" );
	set("age", 47);
	set("int", 26);
	set("long",
		"κ�޼��Ǹ���ѧ���ŵĽ���������������ʱ�����й����ˣ�����\n"
		"��Ϊ����ϲ�����ɶ���Ը���٣�κ�޼��Խ���Ϊҵ������㸶��\n"
		"һ��ѧ�ѣ��Ϳ��Գ�Ϊ���ĵ���ѧϰ����ʶ�֡�\n");
	set("inquiry", ([
		"ѧ��": ({
			"�� ... ����ʶ�������˵ĵ�һ����",
			"ѧ���˶���ʶ�ֵı��죬ʤ���ڰ���ļҲơ�",
			"����˵ѧ���ǽ�Ǯ�򲻵��ġ�",
			0,
			0,
			0,
			(: command, "hmm" :),
			"��Ȼѧ�����޼۵ģ�������������ĵĻ� ...",
			"ֻҪ�������ӡ�",
			}),
		"����ʶ��": "�ԣ�����ʶ�֡�",
		"����»": ({
			"Ŷ ... ����˵Ұ��ɽկ�Ķ�կ�����˳�Ѫ������������»��",
			"���ֳ��������ˣ�",
			(: command, "hmm" :),
			"�����ȥ���������Ҹ���˵���仰��",
			(: follow_player :),
			})
	]) );
	set("attitude", "peaceful");
	set_skill("literate", 60);
	setup();
}

/*
void follow_player()
{
	object ob;

	if( !objectp(ob = query_temp("last_asker")) ) return;
	set_leader(ob);
}

*/
int recognize_apprentice(object ob)
{
	if( !ob->query("marks/κ�޼�") ){
		say("κ�޼�˵�����ף��Ҳ��ǵ��չ������ѧ����....\n");
		return 0;
	}

	return 1;
}

int accept_object(object who, object ob)
{
	if( !who->query("marks/κ�޼�") ) {
		if( ob->value() >= 500 ) {
			say("κ�޼����˵�ͷ��˵�����ܺã��ӽ���������ʱ�����������йض���ʶ��(literate)\n"
				"                      ���κ����⡣\n");
			who->set("marks/κ�޼�", 1);
			return 1;
		} else {
			say("κ�޼�˵������ĳ��ⲻ������Ǯ�����û�ȥ�ɡ�\n");
			return 0;
		}
	} else
		say("κ�޼����˵�ͷ��˵����Ŷ��������ô���ĵ�ѧ�������ǲ�������ú�Ŭ��\n"
			"                      �����ض�ǰ;������л�ˡ�\n");
	return 1;
}

int accept_learn(object me, string skill)
{
	return 1;
}
