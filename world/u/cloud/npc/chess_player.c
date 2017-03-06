// chess_player.c

inherit NPC;

string play_chess();

void create()
{
        set_name("����", ({ "chess player", "player" }) );
        set("gender", "����" );
        set("age", 43);
        set("long", "һλʮ�����������ӣ�װ��������塣\n");
	set("str", 12);
	set("int", 28);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("dodge", 80);
	set_skill("throwing", 30);

        set("inquiry", ([
		"����" : (: play_chess :),
        ]) );

	setup();
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
//	for(int i=1; i<=100; i++){
		carry_object("/u/cloud/obj/npc/chess_player/chess")->wield();
//	}
}

string	play_chess()
{
        command("say Ҫ����һ�̣��ð���");
	if(random(100)<50)
	{
		command("say ���弼�����������Ϊ�����͸�����ö���ӷ���ɣ�");
		printf("%s", name(this_player()) );
		command( "give chess to " + name(this_player()) );
		return "0";
	}
	else
		command("say ���ó��ã�");
	return "1";
}

