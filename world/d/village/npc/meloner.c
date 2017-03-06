// monk.c

inherit NPC;
inherit F_VENDOR;

void catch_thief();

void create()
{
	set_name("��ũ", ({ "meloner" }) );
	set("gender", "����" );
	set("age", 46);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
һ�������ũ�����ϱ�����ɹ����ڣ�һ��ļ���
�⣬���˵ĸо�����ʵ���͡�
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	(:catch_thief:), }) );	
	//set("inquiry", ([
//		"": "",
//	]) );

	set("vendor_goods", ([
                "����": "/d/village/obj/melon",
        ]) );      
        
	set("force", 500);
        set("max_force", 500);

        set("mana", 50);
        set("max_mana", 50);

        set("combat_exp", 8000);
        set("score", 100);

        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	set_skill("chaos-steps",30);
	set_skill("fonxansword",30);
	set_skill("fonxanforce",30);
	map_skill("parry", "fonxansword");
        map_skill("dodge", "chaos-steps");
	map_skill("force","fonxanforce");
	setup();

        carry_object("/obj/cloth")->wear();
//	carry_object("/obj/weapon/longsword")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
	add_action("do_return", "return" );
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "��λ" + RANK_D->query_respect(ob)
                + "Ҫ��Ҫ������Ͻ��ʣ�\n");
}

int do_return(string arg)
{
	if( !this_player()->query_temp("melon/catch_thief") )
	  return notify_fail("����ûǷ��ʲô��ΪʲôҪ����\n" );
	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
	if( arg=="melon cost" || arg=="��Ǯ" )
	{
	  command("say �ã��������˾�����ˡ�\n");
	  set_temp("melon/catch_thief",0);
	  this_player()->set_temp("melon/catch_thief",0);
	  set_leader(0);
	  move(find_object("/d/village/melonguard"));
	  return 1;
	}
	return notify_fail("���˹�Ǯ����ʲô����Ҫ��\n");
}

void catch_thief()
{
	if( query_temp("melon/catch_thief") )
	  command( "say ��Ҫ�����ҹ�Ǯ(return melon cost)����������û�꣡\n" );
	else
	  command( "heihei this_player()" );
}
