// xkx.zhang san.c
// dan

inherit NPC;



void create()
{
	set_name("����", ({
		"zhang san",
		"zhang",
	
	}));
	set("long",
		"����һλ��ĸߴ�������ˣ�Ц�ݿ��䣬�����͵�������ʹ�ߡ�\n"
		
	);


	set("gender", "����");
	set("attitude", "friendly");


	set("age", 40);
	
	create_family("���͵�", 2, "����");




	setup();

        carry_object("/obj/cloth/blackrobe")->wear();
}
