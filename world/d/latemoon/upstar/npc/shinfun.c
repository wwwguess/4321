inherit NPC;
string do_reply();
 
void create()
{
        set_name("Ī����" , ({ "shinfun","fun","girl" }) );
        set("gender", "Ů��" );
        set("age", 27);
        set("long", @TEXT
����ɫ���㣬�������ף�����浾��������御�
�����ݾ��������������������������ŵ�һ����
���㡣
TEXT
);
	set("inquiry", ([
		"������":
		(: do_reply :),
	]) );
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 70);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);
       set_temp("apply/armor", 70);
       set_temp("apply/attack", 50);

        create_family("����ׯ",2,"����");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/belt")->wear();
        carry_object("/d/latemoon/obj/clasp")->wear();
}

string do_reply()
{
	this_player()->set("mark/dance-book",1);
	return("�����װ���ʦ��������ϰ�貽��ʱ����õ��ţ�\n"+
"��Ҳ��ѧ�� ����...\n");
}

