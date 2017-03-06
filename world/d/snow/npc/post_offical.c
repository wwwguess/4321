// post_officer.c

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("ѩͤ���Ų�", ({ "post offical", "offical" }) );

	set("gender", "����" );
	set("age", 28);
	set("long",
		"��������������ѩͤ���ˣ������ſ��Ϊ�ˣ���Ͼʱ��ѩͤ��\n"
		"��æ���������нˮ���ſ���ǹ��ⲻȥ�����ü���Ҳ��ֻ����\n"
		"���������Լ�һ����ѧ��������������\n");
	set("combat_exp", 600);
	set("attitude", "friendly");
	set("inquiry", ([
		"��վ" : "�ǰ�... �������ѩͤ�䣬��Ҫ������",
		"����" : (: send_mail :),
		"����" : (: receive_mail :),
	]) );
	set_skill("literate", 60);
	set_skill("dodge", 90);
	set_skill("unarmed", 70);
	setup();
	add_money("coin", 70);
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ������е��Ŷ������档\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}
