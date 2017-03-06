// scholar.c

inherit NPC;
string answer_right();

void create()
{
set_name("女生",({"scholar"}) );
        set("gender","女性");
        set("long",@LONG
她神采飞扬，好象她知道一个关于河海大学的秘密。
    她那么活泼可爱，如果问她有什么秘密（secret），相信她一定会告诉你。
LONG
);
	set("age", 23);
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
        set("chat_chance",25);
	set("chat_msg", ({
        "学生说：你需要帮助吗？\n",
        "学生悄悄地说：我有一个秘密（secret），你听不听？\n",
        (: random_move :),
	}) );
        set("inquiry",([
            "secret":
                     (: answer_right :),
       ]));
	setup();
	carry_object(__DIR__"obj/book");
	carry_object("/obj/cloth")->wear();
}
string answer_right()
{
    return "网络管理中心有间时空转移站,你可以去试试看!\n";
}

