// scholar.c

inherit NPC;
string answer_right();

void create()
{
set_name("Ů��",({"scholar"}) );
        set("gender","Ů��");
        set("long",@LONG
����ɷ��������֪��һ�����ںӺ���ѧ�����ܡ�
    ����ô���ÿɰ������������ʲô���ܣ�secret����������һ��������㡣
LONG
);
	set("age", 23);
	set("attitude", "peaceful");
	set("combat_exp", 10);
	set("env/wimpy", 100);
        set("chat_chance",25);
	set("chat_msg", ({
        "ѧ��˵������Ҫ������\n",
        "ѧ�����ĵ�˵������һ�����ܣ�secret��������������\n",
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
    return "������������м�ʱ��ת��վ,�����ȥ���Կ�!\n";
}

