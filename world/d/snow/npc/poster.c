// post_officer.c

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("雪亭驿信差", ({ "post offical", "offical" }) );

	set("gender", "男性" );
set("age", 28)
	set("long",
		"他是土生土长的雪亭镇人，因景仰杜宽的为人，闲暇时来雪亭驿\n"
		"帮忙，坚决不收薪水，杜宽很是过意不去，推让几番也就只好依\n"
		"他，但将自己一生所学尽数传授与他。\n");
	set("combat_exp", 600);
	set("attitude", "friendly");
	set("inquiry", ([
		"驿站" : "是啊... 这里就是雪亭驿，你要寄信吗？",
		"寄信" : (: send_mail :),
		"收信" : (: receive_mail :),
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
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
