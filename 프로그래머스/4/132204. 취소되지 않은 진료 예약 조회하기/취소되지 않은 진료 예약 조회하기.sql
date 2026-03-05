select a.APNT_NO,p.PT_NAME,a.PT_NO,a.MCDP_CD,d.DR_NAME,a.APNT_YMD from appointment as a 
inner join doctor as d on a.mddr_id = d.dr_id
inner join patient as p on p.PT_NO = a.pt_no
where APNT_YMD >= "2022-04-13" and APNT_YMD < "2022-04-14" and APNT_CNCL_YN = 'N' order by APNT_YMD;