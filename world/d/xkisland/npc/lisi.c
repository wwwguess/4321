// xkx.lisi.c李四
// dan

inherit NPC;

string ask_me_1();  
void consider();
void create()
{
	set_name("李四", ({
		"li si",
		"li",
	
	}));
	set("long",
		"他是一位身材高大的中年人，面色阴沉，是侠客岛的罚恶使者。\n"
		
	);


	set("gender", "男性");
	set("attitude", "friendly");


	set("age", 40);
	
	create_family("侠客岛", 2, "弟子");

	set("inquiry", ([
		"腊八粥" :    (: ask_me_1 :),
		
	]));

	set("zhou_count", 3);
	setup();

        carry_object("/obj/cloth/blackrobe")->wear();
}
void init()
{
    ::init();
    call_out("greeting",1,this_player());
}

void greeting(object me)
{
    remove_call_out("greeting");
    tell_object(me,@LONG
您先请里面坐，我们马上...上宴...
LONG);
} 
string ask_me_1()
{
	mapping fam; 
	object ob;
	
	
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚给你一碗，怎麽又来要了？ 此粥数量不多，过段时间再来吧。";

	if (  present("laba zhou", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有一碗吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("zhou_count") < 1) return "对不起，粥已经发完了";

	ob = new("/d/xkisland/obj/zhou");
	ob->move(this_player());

	add("zhou_count", -1);

	message_vision("$N获得一碗粥。\n",this_player());
	return "好吧，记住，趁热吃。";

}


