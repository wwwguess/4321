// xkx.di zi.c
// dan

inherit NPC;
 void create()
{
	set_name("����", ({
		"di zi",
	
	}));
	set("long",
		"����һλ��ĸߴ��������,רְӭ�������͵���������ʿ.\n"
		
	);


	set("gender", "����");
	set("attitude", "friendly");


	set("age", 20);
	
	create_family("���͵�", 3, "����");




	setup();

        carry_object("/obj/cloth/blackrobe")->wear();
}
