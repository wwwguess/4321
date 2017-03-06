// roomgirl.c 房产小姐
// by 柳残阳
inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("推销小姐", ({ "girl" }));
	set("long", "一位打扮得花枝招展的小姐！\n");
	set("gender", "女性");
	set("age", 20);
	set_skill("literate", 100);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
//	set("shen_type", 1);
	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
		"销售小姐说：您是来买房的吧？我们这里的服务包您满意。\n"
		"销售小姐微微一笑，令你神魂颠倒！\n",
		"销售小姐高兴的看了你一眼！\n",
			}) );
}
void init()
{
}
int accept_object(object who, object ob)
{       if (this_player()->query("age")<18) 
        {      write("你太小，过些日子再来买房吧！\n");
               return 0;
        } 
        if (!undefinedp(this_player()->query("myroom")))
        {     write("销售小姐不解的说，您已经买过房了呀！\n");
              return 0;
        }
	if (ob->query("money_id") && ob->value() >= 1000000) {
		message_vision("销售小姐高兴的对$N说：好吧，请到花园别墅区看看您的新房吧。\n", this_player());
	        this_player()->set("myroom/time",time());
		return 1;
	}
}
