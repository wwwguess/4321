// kid.c

inherit NPC;

void create()
{
	set_name("����",({ "shusheng" }) );
        set("gender", "����" );
        set("age", 17);
        set("long", "���Ǹ�����־������\n");
        set("combat_exp", 500);
//        set("shen", 50);
	set("shen_type", 1);
	set("str", 21);
	set("dex", 21);
	set("con", 21);
	set("int", 21);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/shuji"+(random(4)+1));
}

