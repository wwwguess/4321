// xkx npc cave10 npc4.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("�޲����", ({"yu cha", "yu"}));
    set("nickname", "�䵱����");
    set("gender", "����");
    set("age", 70);
    set("long", 
      "���׷�ͯ�գ��������͵�������ѧ��ʮ�ꡣ\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/obj/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}






