// rysj master.c
// write by dfbb@hero
// 1/25/96
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
string tang="天风堂";
void create()
{
           set_name("桑三娘" , ({"sang san niang", "sang"}));
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR + GRN+ tang+ NOR +"堂主");	
	set("long", 
		"一身短打的中年妇人\n");
	set("gender", "女性");
	set("age", 41);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 50);
	set("combat_exp", 150000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("tianmo-dafa", 100);
	set_skill("dodge", 100);
	set_skill("mo-shan-jue", 100);
        set_skill("strike", 100);
	set_skill("mo-zhang-jue", 100);
	set_skill("parry", 100);
	set_skill("literate", 50);
	 set_skill("fork",100);
         set_skill("mo-cha-jue",100);   
         map_skill("fork","mo-cha-jue");
         map_skill("parry","mo-cha-jue");


	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");

        prepare_skill("strike", "mo-zhang-jue");

	create_family("日月神教", 15, "长老");

	set("inquiry", ([
		"秘籍" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/d/heimuya/obj/fork")->wield();
	carry_object("/obj/cloth")->wear();
	
}

void attempt_apprentice(object ob)
{
	if(this_player()->query("family/family_name")!="日月神教")
	 {
          write( RANK_D->query_respect(this_player()) +
                "还是请回吧!我不收教外之人\n");
	  return;	
	 }
        if(this_player()->query("whichtang")!=0&&this_player()->query("whichtang")!=tang)
	 {
	   write( RANK_D->query_respect(this_player()) +
                "你不是本堂弟子,请回吧\n");
           return;
	 }
	command("say 好吧，我就收下你了。\n");
	command("say 从今天起,你就是我们"+tang+"的一员了!\n");
	command("recruit " + ob->query("id"));
	this_player()->set("whichtang",tang);
        this_player()->set("title",HIR "日"+HIB"月"+HIY "神教" NOR + GRN +tang+ NOR
+"弟子");
	
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (this_player()->query("family/family_name")!="日月神教")
		return RANK_D->query_respect(this_player()) + 
		"与本教素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本教的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/d/heimuya/obj/force_book");
	ob->move(this_player());
	return "好吧，这本「天魔大法」你拿回去好好钻研。";
}
